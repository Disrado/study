#include "SceneManager.hpp"

SceneManager::SceneManager(sf::RenderWindow *_renderWindow, tgui::Gui *_gui)
{
    renderWindow = _renderWindow;
    gui = _gui;
    playScene = nullptr;
    
    currentScene = this->createScene(Scenes::Start);
    currentSceneType = Scenes::Start;
}

Scene* SceneManager::createScene(Scenes _sceneType)
{
    switch (_sceneType) {
    case Scenes::Start:
        return (Scene*)new StartScene(renderWindow->getSize(), gui, this);
        break;
    case Scenes::Play:
        playScene = new PlayScene(renderWindow->getSize(), gui, this);
        return (Scene*)playScene;
        break;
    case Scenes::Settings:
        return (Scene*)new SettingsScene(renderWindow->getSize(), gui, this);
        break;
    case Scenes::Pause:
        return (Scene*)new PauseScene(renderWindow, gui, this);
        break;
    case Scenes::PrePlay:
        return (Scene*)new PrePlayScene(renderWindow->getSize(), gui, this);
        break;
    case Scenes::End:
        return (Scene*)new EndScene(renderWindow->getSize(), gui, this);
        break;
    }
}

void SceneManager::replaceCurrentScene(Scenes _newScene)
{
    switch(_newScene) {
    case::Scenes::Start:
        if(currentSceneType == Scenes::Play) {
            delete playScene;
        } else {
            delete currentScene;
            currentScene = this->createScene(Scenes::Start);
        }
        break;

    case::Scenes::PrePlay:
        delete currentScene;
        currentScene = this->createScene(Scenes::PrePlay);
        break;
        
    case::Scenes::Play:
        if(currentSceneType == Scenes::Pause) {
            delete currentScene;
            currentScene = playScene;           
        } else {
            delete currentScene;
            currentScene = this->createScene(Scenes::Play);
        }
        break;
        
    case::Scenes::Settings:
        delete currentScene;
        currentScene = this->createScene(Scenes::Settings);
        break;
        
    case::Scenes::Pause:
        if(currentSceneType == Scenes::Pause || currentSceneType != Scenes::Play)
            break;
        else {
            currentScene = this->createScene(Scenes::Pause);
        }
        break;

    case::Scenes::End:
        delete currentScene;
        currentScene = this->createScene(Scenes::End);
        break;
    }

    currentSceneType = _newScene;
}

Scenes SceneManager::getCurrentSceneType()
{
    return currentSceneType ;
}

PlayScene* SceneManager::getPlayScene()
{
    return playScene;
}
    
void SceneManager::drawScene()
{
    currentScene->draw(renderWindow);
}
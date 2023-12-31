//
// Created by luoyue on 2023/10/7.
//

#ifndef LYTOY_ENIGNE_SCENE_H
#define LYTOY_ENIGNE_SCENE_H

#include "defines.h"
#include "Sprite.h"

class Scene : public GameObject
{
public:
    explicit Scene(const char* file_name);

    ~Scene();

    void render(Render* render);

    void render(Render *render, double angle, SDL_Point *center, auto flip);

    //加载精灵
    virtual void load_sprite(Render* render);
    virtual void load_sprite(Render* render, Sprite* sprite);
    virtual void load_sprite(Render* render, int id);
    virtual void load_sprite(Render* render, const char* name);

    //渲染精灵
    virtual void render_sprite(Render* render);
    virtual void render_sprite(Render* render, Sprite* sprite);
    virtual void render_sprite(Render* render, int id);
    virtual void render_sprite(Render* render, const char* name);

    virtual ull add_sprite(Sprite* sprite);

    virtual int get_sprite_id(Sprite *sprite);
    virtual Sprite* get_sprite(int id);

    //删除精灵
    virtual void del_sprite(Sprite* sprite);
    virtual void del_sprite(int id);
    virtual void del_sprite(const char* name);
    virtual void del_sprite();

    //处理事件
    virtual void handle_event(GameEvent event);
    ull add_event(int id, const std::function<void()>& func);
    void del_event(int id);
    void change_event(int id, std::function<void()> func);
    void set_event(int id);

    //处理更新
    void update();
    ull add_update(const std::function<void()>& func);
    void del_update(int id);
    void change_update(int id, std::function<void()> func);
    void set_update(int id);
    void handle_update(int id);

    void on_key(GameEvent event, int key_id, const std::function<void()>& func);

protected:
    std::vector<std::pair<int, std::function<void()>>> event_lists;
    std::vector<std::function<void()>> update_lists;
private:
    std::vector<std::pair<int, Sprite*>> sprites;
};

#endif //LYTOY_ENIGNE_SCENE_H

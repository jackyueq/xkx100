// loveroom.c ��Լ��
#include <ansi.h>
#include <room.h>
inherit ROOM;

varargs static void
create_food(string nmstr, string* idlist, string longstr)
{
        object obj;

        obj = new("/d/city/obj/food");
        obj->set_name(nmstr, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", "һ����������, �������"+nmstr+"��\n");
        obj->move(this_object());
}

varargs static void
create_water(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new("/d/city/obj/water");
        obj->set_name(cup, idlist);
        if (longstr)
              obj->set("long", longstr);
        else
              obj->set("long", "һ���ɿڵ�" + nmstr + "��\n");
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

varargs static void
create_wine(string nmstr, string* idlist, string cup, string longstr)
{
        object obj;

        obj = new("/d/city/obj/wine");
        obj->set_name(cup, idlist);
        if (longstr)
                obj->set("long", longstr);
        else
                obj->set("long", "һ��������" + nmstr + "��\n");
        obj->set("liquid/name", nmstr);
        obj->move(this_object());
}

void create()
{
        set("short", MAG"��Լ��"NOR);
        set("long", @LONG
¥��¥����Լ��������ͨ����������棬������ů��Զ���յ�һ
�ߣ�ӳ������������ɽ��ѹ�̣����֣�������Ŷ������أ�������ɴ��
��ݺ���䡣�����׵̺�ب���ϣ������������أ����ݺ�����һ�α̳�
ƮȻ���档����һ�ž��ɵ�С��������һֽ���µĲ˵�(menu)��
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "down" : __DIR__"jiulou",
        ]));
        set("sleep_room",1);
        set("item_desc", ([
            "menu": @TEXT
        order party:    Ũ���Ļ�    (200������)

        order end  :    ������

        close door  :   �رշ���

        open door   :   �򿪷���

TEXT
        ]) );
        //create_door("down", "��ľ����", "up", DOOR_OPENED);
        set("no_clean_up", 0);
	set("coor/x", 4160);
	set("coor/y", -1450);
	set("coor/z", 10);
	setup();
        set("no_user", 1);
}

void init()
{
        object me;

        add_action("do_order", "order");
        add_action("do_close","close");
        add_action("do_open","open");
        add_action("do_broadcast", "broadcast");
        if (query("order_owner")) {
                me = this_player();
                me->set("food", me->query("food") / 2);
                me->set("water", me->query("water") / 2);
        }
}

int do_broadcast(string arg)
{
        string type;
        string mesg;
        object me;

        me = this_player();
        if (query("order_owner") != me->query("id"))
                return 0;
        type = query("order_type");
        if (type == "party") {
                mesg = me->name() + "�ں���¥��¥��ĳ���Ļ� !!!!!!\n";
        message("channel:chat", RED+"��ͨ�桿"+mesg+NOR, users() );
        message("channel:chat", GRN+"��ͨ�桿"+mesg+NOR, users() );
        message("channel:chat", CYN+"��ͨ�桿"+mesg+NOR, users() );
        return 1;}
}

int do_order(string arg)
{
        object me, env;
        object* oblist;
        string mesg;
        int idx;

        me = this_player();
        env = this_object();
        mesg = query("order_owner");
        if (mesg && (arg == "end") && (mesg == me->query("id"))) {
                mesg = "�Ļ����ڽ����� !!!!!!\n";
                message("channel:chat", RED+"��ͨ�桿"+mesg+NOR, users() );
                delete_temp("plugin");
                delete("order_owner");
                delete("order_type");
                oblist = all_inventory(env);
                for(idx=0; idx<sizeof(oblist); idx++) {
                        if (!objectp(oblist[idx]))
                                continue;
                        if (userp(oblist[idx]))
                                continue;
                        destruct(oblist[idx]);
                }
                return 1;
        }
        if (mesg)
                return notify_fail("�����Ѿ����˰�����.\n");
        notify_fail("��û���㹻��Ǯ����Ǯ����.\n");
        if (arg == "party") {
                mesg = me->name() + "��ĳ���ں���¥��¥�Ļ� !!!!!!\n";
                if (me->can_afford(20000) == 0)
                        return 0;
                me->pay_money(20000);
                create_water(CYN"������"NOR, ({ "tea" }), MAG"��ɰ����"NOR );
                create_water(HIG"���ݴ�"NOR, ({ "tea" }), MAG"��ɰյ"NOR );
                create_wine(HIY"���˻ƾ�"NOR, ({ "wine" }), HIW"������"NOR );
                create_wine(GRN"��Ҷ��"NOR, ({ "wine" }), HIG"��䱭"NOR );
                create_wine(RED"Ů����"NOR, ({ "wine" }), MAG"��̴��"NOR );
                create_food(RED"������"NOR, ({ "pork" }) );
                create_food(HIB"��������"NOR, ({ "fish" }) );
                create_food(HIR"����Ϻ��"NOR, ({ "shrimp" }) );
                create_food(YEL"�л�ͯ��"NOR, ({ "chicken" }) );
                create_food(HIR"��������"NOR, ({ "guihua geng" }) );
                create_food(HIY"�ٹ��Ͱ�"NOR, ({ "baozi" }) );
                }
         else {
                return notify_fail("���ֻ�а��Ļ�С�硣\n");
        }
        message("channel:chat", RED+"��ͨ�桿"+mesg+NOR, users() );
        message("channel:chat", GRN+"��ͨ�桿"+mesg+NOR, users() );
        message("channel:chat", CYN+"��ͨ�桿"+mesg+NOR, users() );
        set("order_owner", me->query("id"));
        set("order_type", arg);
        return 1;
}

int do_close(string arg)
{
        object me=this_player();
        object room;
        if(arg!="door") return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() || me->is_fighting())
                 return notify_fail("����æ���ء�\n");
        room=this_object();
        room->delete("exits/down");
        (int)me->query_temp("plugin");
        me->set_temp("plugin",1);
        me->start_busy(10);
        message("channel:chat", HIR+"��ͨ�桿"+me->name()+"���Ŷ������� !!!!\n"NOR, users() );
        return 1;
}

int do_open(string arg)
{
        object me=this_player();
        object room;
        if(arg!="door") return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() || me->is_fighting())
                 return notify_fail("����æ���ء�\n");
        room=this_object();
        room->set("exits/down",__DIR__"jiulou");
        (int)me->query_temp("plugin");
        me->delete_temp("plugin",1);
        me->start_busy(10);
        message("channel:chat", HIR+"��ͨ�桿"+me->name()+"���ڴ����� !!!!\n"NOR, users() );
        return 1;
}

int valid_leave(object me, string dir)
{
        if (me->query("id") != query("order_owner"))
                return 1;
        return notify_fail(RED + "���� order end ����������.\n" + NOR);
}
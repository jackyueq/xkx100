// Room: /d/wudujiao/tree.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "������");
        set("long", @LONG
�����Ǵ����Ķ��ˣ�������Ũ�ܵ�֦Ҷ��ʪ������̦޺��һ��
΢�紵������Ҷ���������������������������ȥ����ֻ����һ��
���Σ����뻹�ǸϿ���ȥ�ɡ�
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
        ]));
        set("objects", ([
                  __DIR__"obj/xiang": 1,
        ]));

        set("coor/x", -44920);
	set("coor/y", -81060);
	set("coor/z", 50);
	setup();
}

void init()
{
        add_action("do_climb","climb");
}
int do_climb(string arg)
{

        object me=this_player();
        object ob;
        if( (!arg) ||!((arg == "tree") || (arg == "down")))
                return notify_fail("��Ҫ��ʲô��\n");
                message_vision("$N����������֦�������������ȥ��\n\n",me);
        ob = load_object(__DIR__"nanyuan");
        ob = find_object(__DIR__"nanyuan");
        message("vision", me->query("name")+"��������������������\n", ob);
        me->move(__DIR__"nanyuan");
        return 1;
}


// Room: /d/wudujiao/minju7.c

inherit ROOM;

void create()
{
        set("short", "ѧ��");
        set("long", @LONG
������һ����ª��ѧ�ã��ƺ��������øĳɵ�,���й����ϻ�����һ
Щ��λ�����������˻ҳ���������.�����ũ��С�����������������顣
LONG
        );

        set("exits", ([
                "out" : __DIR__"cun7",
        ]));
        set("objects", ([
                __DIR__"npc/xuetong": 3,
                __DIR__"npc/xiansheng": 1,
        ]));
        set("item_desc", ([
                "����": "һ���¾ɵĹ�����������źں�����̨��һֱ�������档\n"
        ]) );

	set("coor/x", -44930);
	set("coor/y", -81010);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_enter", "enter");
}
int do_enter(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" ) return 0;
        if( arg=="����" ) {
                message("vision",me->name() + "һ�����������������˽�ȥ��\n",environment(me), ({me}) );
                me->move(__DIR__"minju9.c");
                message("vision",me->name() + "���������˽�����\n",environment(me), ({me}) );
                return 1;
        }
}
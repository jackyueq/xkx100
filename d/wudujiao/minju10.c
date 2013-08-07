// Room: /d/wudujiao/minju10.c

inherit ROOM;

void create()
{
        set("short", "��Ժ");
        set("long", @LONG
����һ�������Χ�ɵļ���Ժ�䣬Զ�����ż����߲ˡ�Ժ��
�м�һ�øߴ�������Ͻ������ʺ�Ĺ�ʵ���Աߵĵ��ϸ���һ��
���Ĳ�ϯ��
LONG
        );
        set("outdoors", "wudujiao");

        set("exits", ([
                "north" : __DIR__"minju6",
        ]));
        set("objects", ([
                  __DIR__"npc/xuetong": 3,
        ]));
        set("item_desc", ([
                "��ϯ" : "\nһ�ź��Ĳ�ϯ���ڶ��ڣ������ƺ���һ���ؽѡ�\n" ,
        ]));
	set("coor/x", -44940);
	set("coor/y", -81040);
	set("coor/z", 0);
	setup();
}
void init()
{
        add_action("do_move", "pull");
}
int do_move(string arg)
{
        object me,hole;
        string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
        if( arg=="��ϯ" ) {
            message_vision("\n$N�ƿ����ڶ��ڵĲ�ϯ������ȥ��\n", this_player());
            me->move(__DIR__"dijiao");
            message_vision("\n���ڶ��ڵĲ�ϯһ�ƣ�$N����������������\n",me);
        }
        else {
            message_vision("\n$N˫���ڿ��бȻ��˼��£����ƺ�ʲôҲûץס��\n", this_player());
        }
        return 1;
}
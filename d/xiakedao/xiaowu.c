// xiaowu.c С��


inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
������һ����С��ʯ�ң���֮������κ�һ����ҪС�ܶ࣬����
����һЩ���߰���ļҾߣ�ǽ�Ǳ߻���һ�����õ�С��(bed) ��ʯ��
�����ǻҳ����Ѿ��þ�û�������ˣ����ǲ����ߴ�ط���ѽ��
LONG );
        set("exits", ([
              "north" : __DIR__"shibi",
        ]));
        set("item_desc", ([
              "bed" : "һ�����ʵ�����������˯��С����\n"
        ]));
        set("no_clean_up", 0);
	set("coor/x", -3080);
	set("coor/y", -25010);
	set("coor/z", 0);
	setup();
}

void init()
{
        add_action("do_move","move");
}
int do_move(string arg)
{
        object me;

        me=this_player();
        if(!arg || arg!="bed") return 0;
        message_vision("$N������С���ƿ����������澹Ȼ��һ������ͨ����\n",me);
         me->move(__DIR__"midao1");
        tell_object(me,"������һ���¡¡���������㶨��һ�����Լ��Ѿ�����������ͨ
�����ˡ�\n");
         return 1;
}
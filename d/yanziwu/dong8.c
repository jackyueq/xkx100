// Room: /d/yanziwu/dong8.c
// Date: Jan.28 2000 by Winder

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������ֲ�����ָ�������������˳�����ң����಻�������ڶ���
����ǰ�У����ų�����������ͼ�ҵ������ķ���
LONG );
	set("exits", ([
		"south"  : __DIR__"dong6",
		"north"  : __DIR__"dong3",
		"east"   : __DIR__"dong4",
		"west"   : __DIR__"dong5",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1190);
	set("coor/y", -1270);
	set("coor/z", 0);
	setup();
}
void init()
{
        object me;
        me=this_player();
        if(me->query_skill("shenyuan-gong",1)>20 && random(me->query("kar"))>20)
             this_object()->set("exits/south", __DIR__"langfang");
	else
             this_object()->set("exits/south", __DIR__"dong6");
        remove_call_out("close");
        call_out("close", 5, this_object());
        return;
}
void close(object room)
{
        this_object()->set("exits/south", __DIR__"dong6");
        return;
}
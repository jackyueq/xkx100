// Room: /d/heimuya/road2.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	 set("short", "����·");
	set("long", @LONG
������һ������·�ϡ�������һ��С�߸ڣ������ն񣬿��öϾ���
�����������Կ���ƽ���ݳǡ�
LONG );
	 set("outdoors", "heimuya");
	 set("exits", ([
	 	"southwest" : __DIR__"road1",
	 	"east" : __DIR__"pingdingzhou",
	 ]));
	 set("no_clean_up", 0);
	set("coor/x", -3010);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	 replace_program(ROOM);
}
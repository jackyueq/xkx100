// Room: /d/heimuya/pingdingzhou.c
// Last Modified by winder on Apr. 10 2000
inherit ROOM;
void create()
{
	set("short", "ƽ����");
	set("long", @LONG
ƽ�����ںӱ����ڣ��ݸ����󣬵��ش�Ҫ�壬ʮ����Ҫ����������
�Ŀ��̴���Ƶ�������ڴ���ϣ����½�ͽ���ֱײ������ץ�ˣ������
���ܣ�ȴ˿��û���ٸ��������
LONG );
	set("exits", ([
		"east" : __DIR__"road3",
		"west" : __DIR__"road2",
	]));
	set("outdoors", "huabei");
	set("no_clean_up", 0);
	set("coor/x", -3000);
	set("coor/y", 4040);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
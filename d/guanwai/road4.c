// /guanwai/road4.c
inherit ROOM;

void create()
{
	set("short", "���");
	set("long", @LONG
������һ����ʯ�̳ɵĴ���ϣ����������ű�ֱͨ��İ���������
����������ȥ��ȫ���ޱ��޼ʵ���Ұ����ߴ��·��м����Ͱ������꣬
Ϊƽ̹�Ĵ�������˼�����͵����ߡ�·�����˽���ϡ��������
LONG );
	set("exits", ([
		"northeast" : __DIR__"road5",
		"southwest" : __DIR__"ningyuan",
	]));
	set("objects",([
		__DIR__"npc/dahu" : 1,
	]));
//	set("no_clean_up", 0);
 	set("outdoors", "guanwai");
	set("coor/x", 6030);
	set("coor/y", 5140);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
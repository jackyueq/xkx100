//HSQCHANGLANG.C

inherit ROOM;

void create()
{
	set("short", "��ˮ�쳤��");
	set("long", @LONG
��������һ������֮�ϣ������������ۣ��������续����С�Ӵ�
���¾������ʣ�����֮��Ʈ���ŵ��������̣�������ɴ�����������־�
��������֣��ƺ�û��һ��������
LONG );
	set("exits", ([
		"north" : __DIR__"hsqdating",
		"out"   : __DIR__"hsqmen",
	]));
	set("outdoors", "mingjiao");
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 940);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
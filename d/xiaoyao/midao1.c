// midao1.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "����ͨ��");
	set("long", @LONG
����һ���ֳ��ֺڵ�����ͨ������Լ���Ըо��������Ǳ������Ӳ
��ʯ�ڣ���ʲô�˿��������ֻ���Կ�������ǰ����
LONG );
	set("exits", ([
		"out" : __DIR__"shishi3",
		"north" : __DIR__"midao2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -30000);
	set("coor/y", -10000);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}

// midao2.c
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
		"south" : __DIR__"midao1",
		"north" : __DIR__"midao3",
	]));
	set("no_clean_up", 0);
	set("coor/x", -40000);
	set("coor/y", -5000);
	set("coor/z", -40);
	setup();
	replace_program(ROOM);
}

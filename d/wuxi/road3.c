// Room: /d/wuxi/road3.c
// Winder 2000/02/22 

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ѿ����������ݸ���Ͻ�ĵؽ��ˣ����ֱֱ������������
��ȥ��·����ʮ�־���ĵ���������·������ȥȥ�ģ�������������
������С�����١�
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"east"  : __DIR__"road4",
		"west"  : __DIR__"road2",
	]));
	set("coor/x", 700);
	set("coor/y", -800);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
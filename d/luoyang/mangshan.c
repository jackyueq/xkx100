// Room: /d/luoyang/mangshan.c
// Last modified by winder 2002.11.11

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
�׻�˵�������պ������ڱ����������˰�������ΰ���������ı�
�����������ߵĺõط����Ͻ���ׯ�帽����ڣ����������Ƕ�������
���������ǵ�Ĺ������
LONG);
	set("exits", ([  /*  sizeof()  ==  2  */
		"northwest" : __DIR__"shangqing",
		"northeast" : __DIR__"lvzuan",
		"southdown" : __DIR__"road6",
	]));
	set("outdoors", "luoyang");
	set("no_clean_up", 0);
	set("coor/x", -500);
	set("coor/y", 50);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

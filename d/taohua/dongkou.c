// Room: /d/taohua/dongkou.c
// Last Modified by winder on Nov. 17 2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���һ������Ȼ��������ôһ���Ҷ����ɼ���������֮�ɡ��Ҷ���
Χȫ���һ��������￴���ں�����ʲôҲ��������
LONG
	);
	set("exits", ([ 
		"west"  : __DIR__"road3",
		"enter" : __DIR__"cave",
	]) );
	set("no_clean_up", 0);
	set("outdoors","taohua");

	set("coor/x", 9200);
	set("coor/y", -3050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
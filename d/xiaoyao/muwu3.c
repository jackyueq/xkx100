// muwu3.c
// Modified by Winder June.25 2000

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����Ҳ��һ��ľ�ݣ������еİ���ʮ�ּ򵥣�����ȴ�кܶ๤�ߣ�
���������������������������ص�ľм��һ����֪����һ�������ļҡ�
�������ǵ��ɽ���æ���أ�������֪����������ʲô�أ�
LONG );
	set("exits", ([
		"north" : __DIR__"mubanlu",
	]));
	set("objects", ([
		CLASS_D("xiaoyao")+"/fengasan": 1,
	]));
//	set("no_clean_up", 0);
	set("coor/x", 90);
	set("coor/y", -520);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
} 
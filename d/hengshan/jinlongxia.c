// Room: /d/hengshan/jinlongxia.c
// Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
	set("short", "����Ͽ");
	set("long", @LONG
����Ͽ�ֳ��������ǽ����ɽ����ڡ���ɽһ��̫��ɽ�����������
�������еı�����������֮Ϊ������С���족������ب���������һ
���н��еĶ��У�������Ϊ����ɽ���С�����ԡ�̩ɽ������������ɽ
������������ɽ���ԡ��͡���ɽ��ɡ���
LONG
	);
	set("exits", ([
		"southeast"  : __DIR__"cuipinggu1",
		"northeast"  : "/d/beijing/road6",
	]));
	set("objects", ([
		CLASS_D("hengshan")+"/jing" : 1,
	]));
	set("outdoors", "hengshan");
//	set("no_clean_up", 0);
	set("coor/x", -20);
	set("coor/y", 3200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


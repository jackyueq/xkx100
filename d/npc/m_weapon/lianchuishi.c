// ROOM lianchuishi.c
// Last Modified by winder on Aug. 25 2001

inherit ROOM;
void create()
{
	set("short", "��ƺ");
	set("long", @LONG
�����������Ŷ��Ĵ���ִ��ĵط������ڻ������̵Ĵ�ѩɽ�ϡ���
ѩɽ�����ѩ������ȴ��һƺ���ݷ��ص�ɽ�ȡ����ܰ��˺ܶ�ͭ�����
һ������������ִ�󴸣��������߽�������
LONG );
	set("exits", ([
		"eastdown" : "/d/xuedao/nroad5",
	]));
	set("objects", ([
		__DIR__"npc/shichui" :1,
	]));
	set("coor/x", -30050);
	set("coor/y", -8000);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}

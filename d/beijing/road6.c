inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ��
��������������߷ɳ۶���������һ·��������·���������������
�����֡�������ԶԶ�ľͿ������������ǡ�������ͨ����ɽ��
LONG );
	set("exits", ([
		"northwest" : __DIR__"road5",
		"southeast" : __DIR__"road7",
		"southwest" : "/d/hengshan/jinlongxia",
	]));
	set("no_clean_up", 0);
 	set("outdoors", "huabei");
	set("coor/x", -10);
	set("coor/y", 3210);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


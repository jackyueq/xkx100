// Room: /d/changcheng/nroad1.c
// Last Modified by Winder on Aug. 25 2000

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵġ�����
�ġ����Ŵ󳵵���򡢴�����˶�������ȥ���ǣ������������ǳ����֡�
��ʱ����������������߷ɳ۶���������һ·��������·����������
����������֡�������ԶԶ�ľͿ������������ǵı����š�
LONG );
        set("outdoors", "changcheng");
	set("exits", ([
		"south" : "/d/beijing/anding",
		"north" : __DIR__"nroad2",
	]));
	set("no_clean_up", 0);
	set("coor/x", -190);
	set("coor/y", 4500);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

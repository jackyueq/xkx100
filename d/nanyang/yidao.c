// Room: /d/nanyang/yidao.c
// Last Modified by winder on Nov. 20 2001

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
������һ����������Ĵ�����ϡ��������������������ӵ����̣�
���Ŵ󳵵�����Ͼ��Ͽ��������������������ǳ����֡���ʱ������
����������߷ɳ۶���������һ·���������ϵ��˸������ž�װ����
���������еĻ���������ŵ�������������Щϰ��Ľ����ˡ���·����
����������������֡��������ݿ쵽�ˡ�
LONG );
	set("exits", ([
		"south" : "/d/city/beimen",
		"north" : __DIR__"yidao1",
	]));
	set("outdoors", "yangzhouw");
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 200);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

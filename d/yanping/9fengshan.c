// Room: /d/yanping/9fengshan.c
// Date: Sep 28, 2002  Winder

inherit ROOM;

void create()
{
	set("short", "�ŷ�ɽ");
	set("long", @LONG
�ŷ�ɽ����Ϫ�븮����������ŷ��ص����������֮�ڣ�������ɽ
�ϻ����ľ�����ľ���������ŷ����ʡ�Ϊ��ƽ�˾�֮һ���δ��Ĵ�����
���������������ｲѧ�������ŷ徰��Ϊ���Ŷ�ܽ�ء������ŵ���������
LONG );
	set("exits", ([
		"east"      : __DIR__"shuyuan",
		"southup"   : __DIR__"baoyunsi",
		"northdown" : __DIR__"fuqiao2",
	]));
	set("objects", ([
		"/d/huashan/npc/youke" : 2,
	]));
	set("outdoors", "yanping");
	set("coor/x", 1480);
	set("coor/y", -6220);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}

// Room: /d/lingxiao/wallw1.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "��ͷ");
	set("long", @LONG
��紵ѩ������ǧ����м���º���գ����������ƿա���ƽ�ز���
ѩ����ɳ����ơ������������������ʵд�ա�Զ����ϡ�ɼ�һ������
���ر���Ϊ�����ӡ��ĺ������ڿ�硢��ѩ�����յ�ӳ���£�������
����֮�ˡ�
LONG );
	set("outdoors", "lingxiao");
	set("exits", ([
		"west"     : __DIR__"wallw2",
		"eastdown" : __DIR__"gate",
	]));
	set("objects", ([
		__DIR__"npc/dizi" : 1,
	])); 
	set("coor/x", -31010);
	set("coor/y", -8930);
	set("coor/z", 150);
	setup();
	replace_program(ROOM);
}


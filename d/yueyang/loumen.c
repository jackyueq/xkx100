// Room: /d/yueyang/loumen.c
// Last Modifyed by Winder on Dec. 4 2001

inherit ROOM;

void create()
{
	set("short", "����¥��");
	set("long", @LONG
����������¥�Ĵ��ţ�������һ���ڵ����ֶ�������ͥ����ˮ����
������¥��������¥����������¥�ϣ�����������ΰ����鶼������
����ƺ�¥���ƽ���������¥��
LONG );
	set("outdoors", "yueyang");
	set("no_clean_up", 0);
	set("exits", ([
		"west"      : __DIR__"huaiputing",
		"southdown" : __DIR__"ximen",
	]));
	set("coor/x", -1430);
	set("coor/y", -2260);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}

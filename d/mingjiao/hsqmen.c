//HSQMEN.C

inherit ROOM;

void create()
{
	set("short", "��ˮ�����");
	set("long", @LONG
���������̺�ˮ��Ĵ��ţ�ׯ�Ϲ��ӣ���ǰ�Բ����������������
ǰˮ��������ȴ��һ��ˮ�������������������ٲ�����Դ��ԭ��������
��ˮ��ͽ���������С��֮�ϡ�
LONG );
	set("exits", ([
		"enter" : __DIR__"hsqchanglang",
		"south" : __DIR__"tohsq7",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52020);
	set("coor/y", 930);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
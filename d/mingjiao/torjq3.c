//TORJQ3.C

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
��·�Ѿ����쵽�˾�ͷ�����׷���һ����¥���ʣ���ǰ��ʮ������
��������Ѳ�ߣ�����ɭ�ϡ���¥���Բ�����������죬ӭ����չ������
��������ɫ���Ž��գ���ʱ�н��ڴӲ�С�Ž�����Ҳ���̲�ý�������
�����У���ȥ��ˮ���·�������Ϸ�����ͨ���һ��졣
LONG );
	set("exits", ([
		"west"      : __DIR__"rjqmen",
		"southwest" : __DIR__"torjq2",
		"northwest" : __DIR__"tohsq1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52000);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
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
		"east" :      __DIR__"jmqmen",
		"southeast" : __DIR__"tojmq2",
		"northeast" : __DIR__"tohtq1",
	]));
	set("no_clean_up", 0);
	set("outdoors", "mingjiao");
	set("coor/x", -52060);
	set("coor/y", 860);
	set("coor/z", 50);
	setup();
	replace_program(ROOM);
}
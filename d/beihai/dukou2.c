// /d/beihai/dukou2.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "�ɿ�");
	set("long", @LONG
������һ���ɿڣ�ר�Ÿ���ڶ��ο��뿪��ȥ������ġ��ɿ���
�ý�ʵ��ľ�Ͻ���ģ���������һ����ӡ��ɴ�Ҳ�Ǻ��µ�˫���δ���
���������ȵ����ġ��������ҷֱ����ڴ�ͷ�ܴ�β����ʱ׼�������ˡ�
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"yilan",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4110);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

// /d/beihai/wulong.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "����ͤ");
	set("long", @LONG
�����ǲ�����ǰ֮����ͤ��ͤ������ˮ�У���ͤ��Ϊ���Σ�ǰ���
�䲼�á���ͤ�����������·��϶��ͣ��������ͤΪ���ܣ�����ͤΪ
���ܣ�����ӿ��ͤ������ͤ��������ͬ����ͤ���������߶������߼��ߣ�
��������ʩС������Ӳʻ���Ѥ����ʡ�
LONG
	);
	set("exits", ([
		"west" : __DIR__"xiaolu2",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -190);
	set("coor/y", 4070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

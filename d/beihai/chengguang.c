// /d/beihai/chengguan.c
// Last Modified by winder on May. 22 2002

inherit ROOM;

void create()
{
	set("short", "�й��");
	set("long", @LONG
����������й�λ���ų����룬�ǿ���ʱ��Ԫ������������
�Ľ��ġ���֮����ṹΪ���Σ�����Ъɽ������������ã���ΪЪɽ����
�����ݶ���������ʹ�֮��¥״�������������û������ߣ����߼��ߡ�
���ڹ�������������������������Ͼ����Ϊ����ʱ����֮����
����һ��ߴ�Ծ������ɣ�������ǣ�Ǭ¡������Ϊ���������
LONG
	);
	set("exits", ([
		"east"  : __DIR__"zhaojing",
		"west"  : __DIR__"yanxiang",
		"north" : __DIR__"jingji",
		"south" : __DIR__"yuweng",
	]));
	set("outdoors", "beihai");
	set("no_clean_up", 0);

	set("coor/x", -180);
	set("coor/y", 4050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

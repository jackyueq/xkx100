// Room: /d/wuyi/huxiaoyan.c
// Last modified by Winder on Mar.20.2002

inherit ROOM;

void create()
{
	set("short", "��Х��");
	set("long", @LONG
����������ɽ��ָ�����Ķ���Ȫ��Ȥ�ļѾ�֮һ����ν����Х����
�ڹ�ʱ���ɣ����ﻢХ�����ϵĵ�ʡ���Х�����и��޶�ÿ��ɽ���ӹ�
�ö����ö��ͻᷢ�����ƻ�Х֮������С֮ʱ��ֻ�ܴ�������������֮
ʱ��ȴ������Ⱥɽ������ë���Ȼ���ִﻢХ���£�̧ͷ���ң�����ӳ
�������ǡ���Ϫ�鶴���ĸ����ָ����ұڣ���������������ʾ��Σ�¸�
�ʣ��᧿�Σ������ۣ���Х���档���������Х�ң���ʫ��������
��Х���ң�ǧ��������̶����
LONG );
	set("outdoors", "wuyi");
	set("no_clean_up", 0);
	set("exits", ([
		"north"   : __DIR__"jingtai",
		"south"   : __DIR__"path6",
		"southup" : __DIR__"tiancheng",
	]));
	set("no_clean_up", 0);
	set("coor/x", 1390);
	set("coor/y", -5030);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}


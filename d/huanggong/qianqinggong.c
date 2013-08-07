// Room: /d/huanggong/qianqinggong.c

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "Ǭ�幬");
	set("long", @LONG
���ǻ��ϵ��޹�. Ǭ����Ϊ��������ƽ��. ����Ҳ��������ѡ�ɹ�
��, ��������, �ټ�����. ���Ϻ��ҡ����������, ��˳�ε۵��ױ���
��, �Ա����Լ�������Ϊ����ֱ��Ⱥ͹��������. �����ĸ���������
���������, һ��������۵�����(kangxi), ��һ����Ǭ¡�ʵ۵�����
(qianlong).
LONG
	);
	set("item_desc", ([
		"kangxi" : "
������� ��������˼��
������ ��������Ω��
\n",
		"qianlong" : "
�˿���� �ʽ����м�
Ω��Ωһ �������ʹ�
\n",
	]));
	set("exits", ([
		"west"      : __DIR__"huangqin",
		"east"      : __DIR__"duanning",
		"south"     : __DIR__"qianqingmen",
		"north"     : __DIR__"jiaotaidian",
		"southeast" : __DIR__"yushufang",
		"southwest" : __DIR__"jingshifang",
	]));
	set("objects", ([
		__DIR__"npc/zhangkangnian": 1,
		__DIR__"npc/zhaoqixian": 1,
	]));
	set("coor/x", -200);
	set("coor/y", 5290);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/taiwan/danshui.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��ˮ");
	set("long", @LONG
��ˮ��λ��̨�嵺�����磬����̨�庣Ͽ������̨��������֮��
ˮ�ӳ����ڱ��������Ϸ���������ɽϵ��������Ӷ�������ɽ����ˮ֮
�����ˮ��������С������ǲ��֮�ƣ����˵��н��غӶ�������ת
����ɽ�£�б�����䣬�ݻؽ�ת֮�䣬����������˼���Ӹ������Ӹۣ�
��Ϊ���С��ƻ�����֮�¡�Ʈҡ�緫���������Բ��⣬��ˮ��⣬
��ʵ��ֹ�ڴˣ�
LONG );
	set("exits", ([
		"east"      : __DIR__"jilonggang",
		"north"     : __DIR__"hongmaocheng",
		"southwest" : __DIR__"zhuqian",
	]));
	set("objects", ([
		__DIR__"npc/pingpu_kdgl": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2540);
	set("coor/y", -6970);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


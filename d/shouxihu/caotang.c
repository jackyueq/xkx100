// Room: /yangzhou/caotang.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "���ϲ���");
	set("long", @LONG
���ϲ���������麡�������������֪��������������ϲ��á�
���������(lian)������ƽ̨Χ��ʯ������ͷ����ʯʨ������Ϊ������
�Σ�ƽ̨��ֲ��һ�԰�����ޱ�����պ컨���ۡ������û�����ͷ������
֮�������ǰ���ƴ����ӿ�ľ��Ƭ��һ��һС������ǧ�����������
������������ľϵľ������ľ�ʼ��ͣ�������δ���࣬�û�������
LONG );
	set("outdoors", "shouxihu");
	set("item_desc", ([
		"lian" : HIW"
        ��        ��
        ��        ��
        ��        δ
        ��        ��

        ��        ��
        ��        ̶
        ��        ת
        ��        ��
\n"NOR
	]));
	set("exits", ([
		"west"    : __DIR__"lunlian",
		"northup" : __DIR__"guanyindian",
	]));
	set("no_clean_up", 0);
	set("coor/x", 10);
	set("coor/y", 110);
	set("coor/z", -10);
	setup();
	replace_program(ROOM);
}
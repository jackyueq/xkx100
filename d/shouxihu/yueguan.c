// Room: /yangzhou/yueguan.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�¹�");
	set("long", @LONG
�¹�����������ǰ�ٺ����������԰���¹�֮�£�����ˮ��������
һ赣�ʵ����������ʤ�ء����������ų��������顰�¹ۡ����ң���ǰ
��һ�������(lian)��Ϊ�����ݰ˹֡�֮һ��֣�������顣�ı�������
Ƭ�����������ʯ�������Ժ�÷Ϊ��ӣľΪ�ţ�ÿƬ��Ƕ�з�Բ����
��Ȼɽˮ���δ���ʯ����������Ϊ����涫����ľ������������
���������ˮ�ʡ�
LONG );
	set("exits", ([
		"west"     : __DIR__"qishi",
		"northup"  : __DIR__"fengting",
	]));
	set("item_desc", ([
		"lian" : HIC"
        ��        ��
        ��        ��
        ��        һ
        ��        ��
        ˮ        ɽ
\n"NOR,
	]));
	set("no_clean_up", 0);
	set("coor/x", 30);
	set("coor/y", 110);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
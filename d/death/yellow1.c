// yellow1.c ��Ȫ���

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", BLU "��Ȫ·" NOR);
	set("long",BLU @LONG
�������Թ�˭���������ӹ�������һֱ�����е������࣬������
ʿ���ܱ���Ľ�֡���ǰ���������Ļ�Ȫ�������������ߣ�һ����ģ
ģ��������Ӱӿ���ţ����߲���һ��������֮����֪�ػ����ţ��ഺ
��פ������������ô�Ķ��ݣ��������ʱ��ȴ���Ƕ�ô������......
LONG NOR);
	set("exits", ([
		"north" : __DIR__"yellow2",
	]) );
	set("no_fight", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}


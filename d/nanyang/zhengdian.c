// Room: /d/nanyang/zhengdian.c
// Last Modified by winder on Nov. 20 2001

#include <ansi.h>
inherit ROOM;
void create()
{
	set("short",RED "����" NOR);
	set("long",@LONG
�����������䣬��ʯΪǽ�����߸������Գ�һ�ɼ��ӵķ�񣬵���
���й���һ������������������ȣ�΢����룬��̬��Ȼ���磻��
��ǽ�������Ų���ʫƪ�ʸ����󶼱ʷ��վ����Ӻ����ѣ���Ȼ�ǳ���һ
Щ�ػ���־��׳�ж�֮�֡�
LONG);
	set("exits",([
		"south" : __DIR__"wuhouci",
	]));
	set("no_clean_up", 0);
	set("coor/x", 20);
	set("coor/y", 530);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

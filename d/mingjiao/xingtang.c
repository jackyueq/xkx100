// Room: /d/mingjiao/xingtang.c

#include <ansi.h>
#include <login.h>

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
���������Ż����գ��ܲ�͸�硣�������ڰ��磬Ҳ�����ҹһ�㣬
ÿ��������ǽ�ϣ���ȼ�ż�֦ţ�;����м���һ������裬�������ڡ�
�·�����һ����������ˮţƤ�ޡ�������弰���������̾ߡ�����վ��
���ֱֳ��е�ִ�����ڡ�����������������������㣬���㲻������
����������
    ��ǫִ���������á�
LONG );
	set("no_fight", "1");
	set("exits", ([
		"west" : __DIR__"square",
	]));
	set("objects",([
		__DIR__"npc/lengqian" : 1
	]));
	set("no_clean_up", 0);
	set("coor/x", -52020);
	set("coor/y", 1050);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
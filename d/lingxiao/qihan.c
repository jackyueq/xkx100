// Room: /d/lingxiao/qihan.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
#include <ansi.h> 
void create()
{
	set("short","������");
	set("long",@LONG
�����������Ǵ���Ӱ��򽣼�����˵�ס����ǽ�Ϲ���һ�����ã�
���顰�������������ʷ�������������ּ������Ϸ���һ��������ƣ�
�������磬һλ��òӢ���������������ԣ��������Եõ��޼����ϵ�һ
��÷����
LONG);
	set("exits",([ /* sizeof() == 1 */
		"east" : __DIR__"houyuan2", 
	]));
	set("objects", ([
		CLASS_D("lingxiao")+"/bai1" : 1,
	]));
	set("coor/x", -31010);
	set("coor/y", -8850);
	set("coor/z", 140);
	setup();
}

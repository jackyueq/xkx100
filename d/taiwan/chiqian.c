// Room: /d/taiwan/chiqiancheng.c
// Last Modifyed by Ahda on Jan. 4 2002

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "��Ƕ��");
	set("long", @LONG
��Ƕ��λ��̨�ϵ�����Ϊ̨�帮פ���������˰�ƽ�������ڳǺ�
Ϊ������Ȩ������һ����������̨�ϵ��������³ǣ��������ڳǻ�Ϊ��
�ǣ���Ϊ�����Ĳ�ǣ����˳�֮Ϊ����Ƕ�ǡ��򡸺�ë¥����һ������
�꣬����ү���ɣ��ڳ�Ƕ���趫�������츮�Ρ���
    ̨��������͢�󳼶��������أ�Ψ��̨����ʩ�����ԣ�����֮
����������֮���̱�Χ�����յñ��������꣬����̨�帮������̨��
��Ƕ�ǡ�
LONG );
	set("exits", ([
		"east"  : __DIR__"donganfang",
		"west"  : __DIR__"xidingfang",
		"south" : __DIR__"ningnanfang",
		"north" : __DIR__"zhenbeifang",
	]));
	set("objects", ([
		__DIR__"npc/bing": 2,
		__DIR__"npc/shilang": 1,
	]));
	set("outdoors", "taiwan");
	set("coor/x", 2510);
	set("coor/y", -7050);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}


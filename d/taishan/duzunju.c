// Room: /d/taishan/duzunju.c
// Last Modified by Winder on Aug. 25 2001
// Modified by Zeratul Jan 11 2001 ������������10000���ܼ�����

#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����Ǵ���᷶���ɽ�����´���ʦ�������������͵ľ�����������
�濪�Ŵ��������⻹�����̵����ֺ��ּ�͸���İ��ơ�����ǽ����һ��
���ã�ʹ��������������ֲ��飺[31;1m
                            ��
                            ��
                            ʦ[0m
    ����ʦ�����������µ�Ӣ����Ʒ�����ǵ��书�������Ը�����
Ʒ���������ʴ���ʦ�������Ƿ�Ը����ְɡ�����ҪС�ģ�����������
��ʦ����ɵ�Ŷ��
LONG );
	set("exits", ([
		"out" : __DIR__"fengchan",
	]));
	set("objects",([
		"/clone/npc/dazongshi" : 1,
	]));
	set("coor/x", 410);
	set("coor/y", 650);
	set("coor/z", 120);
	setup();
	replace_program(ROOM);
}


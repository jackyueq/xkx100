//room: shoushe.c
inherit ROOM;

void create()
{
	set("short","����");
	set("long", @LONG
������ؤ����ӵ����ᡣ���﻿���˸������ޣ��Թ�������ؤ��
����ʹ�á����������޳���˻������Զ�����ü���������ҹ��������
������˺���ѷεĲ��ҡ�����������һȺ��(pig) ��������ǰ�̲���
��Զ��
LONG );
	set("exits",([
		"east"  : __DIR__"pomiao",
	]));
	set("outdoors", "yangzhoue");
	set("item_desc",([
		"pig":
"   ^..^  ^. .^   ^..^   ^..^ ^..^ ^��^  ^..^         ^..^ ^qp^  ^cc^  ^@@^
   (oo) ( o o )  (OO)  (oo ) (@@) (oo)         (00)  (qp) (oo)  (oo)  (oo)

    ��   ����   ��ǡǡ ��ʹ  ̨�� ˯�� �ڰ��� ��Ӿ�� ��ð ���� ��б�� ������
                �͵��� ����  ����       ����   ����  ���� ����  ����
",
	]));
	set("objects",([
		"/d/baituo/npc/fox" :1,
		"/d/baituo/npc/wolf" :1,
		"/d/baituo/npc/tiger" :1,
		"/d/baituo/npc/lion" :1,
	]));
	set("coor/x", 60);
	set("coor/y", 60);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
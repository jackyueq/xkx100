// Room: /yangzhou/xichuntai.c
// Last Modified by Winder on Jul. 20 2000
#include <ansi.h>;
inherit ROOM;

void create()
{
	set("short","����̨");
	set("long",@LONG
����̨�涫��麣��������ܣ�ǰ�ӱ��ã��߼�����Ъɽ���ϸ�����
�����ߣ���������ͼ����������������ȣ�¥������Χ�Լ������Ա�
Զ����ʮ���źͺ�ɽʤ�����ײ㣬�����������顰��̨ף�١��Ҷ��
�����ҽ�������(lian)��ӭ���о޷�����Ů��ҹ����ͼ����Ϊ������
������Ʒ���ửǰ��������������Բ�ʣ���������ݡ�
LONG );
	set("item_desc", ([
		"lian" : HIM"
ʤ�ؾݻ��ϣ�����Ӱ���գ���ˮƽ����һɫ
���۹����£��������δ������˴���������
\n"NOR,
	]));
	set("exits", ([
		"eastdown" : __DIR__"pingtai5",
		"up"       : __DIR__"xichuntai1",
	]));
	set("no_clean_up", 0);
	set("coor/x", -60);
	set("coor/y", 100);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}
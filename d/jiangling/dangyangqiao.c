//Edited by fandog, 01/31/2000

inherit ROOM;

void create ()
{

	set ("short", "������");
	set ("long", @LONG
һ����ľ�ţ��Ѿ��е�ҡҡ��׹�������ŷɺ�ì������ͷ��������
�ȣ����������������Ҳ��˭�����Ҿ�һ��ս�����������ף�������ϣ�
��ˮ��������ͷ����һ��ʯ�� (bei)��������������һ��������Ͽ�ȣ�
��ˮ�ڹȼ�����������ǧ�������ڶ�ȥ�������ǳ�����������һ��
Сɽ�¡�
LONG);
	set("outdoors", "jiangling");
	set("item_desc", ([
		"bei":"\n����º�ì��\n"                    
	]));

	set("exits", ([ 
		"south" : __DIR__"yidao1",
		"east"  : __DIR__"chenglingji",
		"north" : __DIR__"wuxia",
		"west"  : __DIR__"changbanpo",
	]));
  
	set("no_clean_up", 0);
	set("coor/x", -1500);
	set("coor/y", -2070);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}

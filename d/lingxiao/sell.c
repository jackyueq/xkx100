// Room: /d/lingxiao/sell.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short", "ˮ����");
	set("long", @LONG 
�����������ǵĴ���--ˮ������������ˮ��������������Ϊ����
������ˮ�����ƣ�����Ҫ��������������Ȼ������������������������
�����˳ơ�ˮ���������ϰ�³�������ڹ�̨��Ц������ͬ������
�ۻ��ۡ�
LONG );
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([
		"paizi" : "ˮ�����ƣ�ͯ������\n
sell        �� 
buy         ��
redeem      ��
value       ����
",
	]));
	set("objects", ([
		__DIR__"npc/laoban" : 1,
		__DIR__"npc/dizi" : 1,
	]));
	set("exits", ([
		"west" : __DIR__"iceroad1",
	]));
	set("coor/x", -30990);
	set("coor/y", -8920);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


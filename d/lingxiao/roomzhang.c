// Room: /d/lingxiao/roomzhang.c
// Last Modified by Winder on Jul. 15 2001

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG 
�߽��������������ǰ���Ǵ��СС��ҩ�ޡ�������ס��������
�ǵ��������������꣬��Ϊ�˺�������԰����ڷ��ĵذѹ���������һ
Щϡ��ҩ������񽻸�������������˵�����������������ã�������һ
Щ����ҩ�Ƹ��Ǽһ�ȡ�
LONG);
	set("exits",([ /* sizeof() == 1 */
		"north"  : __DIR__"zoulang2", 
	]));
	set("objects", ([  
		__DIR__"npc/zhang" : 1,
		__DIR__"obj/icesword" : 3,
	]));
	set("coor/x", -30990);
	set("coor/y", -8880);
	set("coor/z", 140);
	setup();
	replace_program(ROOM);
}


//Room: /d/dali/yuxuguan.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","�������");
	set("long",@LONG
�������ʮ����죬���й����Ź��ϡ�������������õȰ��ɵ�
����������ƣ������ϰ���Щ��ҡ����з��˼������š��Ա�һ��
С����������Σ�������ɢ����Ϣ����ͽ�ĵط���
LONG);
	set("objects", ([
	   CLASS_D("dali")+"/daobaifeng": 1,
	]));
	set("outdoors", "dalic");
	set("exits",([ /* sizeof() == 1 */
	    "south"  : __DIR__"yuxuguanqian",
	]));
	set("coor/x", -39000);
	set("coor/y", -68980);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
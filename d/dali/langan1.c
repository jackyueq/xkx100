//Room: /d/dali/langan1.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����");
	set("long",@LONG
��������������ľ�Ծ����ϣ����Ǹ�������������������̡�
�乹���������¥�����濪�ţ����ݿ����£��ϸ��糵��״���в�ס
�ˣ��������²㣬һ��Ϊţ��Ȧ��
LONG);
	set("objects",([
	    __DIR__"npc/shanyang" : 2,
	]));
	set("outdoors", "dalie");
	set("exits",([ /* sizeof() == 1 */
	    "north"   : __DIR__"nongtian2",
	    "up"      : __DIR__"langan2",
	]));
	set("coor/x", -31000);
	set("coor/y", -70610);
	set("coor/z", 20);
	setup();
	replace_program(ROOM);
}
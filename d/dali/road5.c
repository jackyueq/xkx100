//Room: /d/dali/road5.c
//Date: June. 29 1998 by Java

inherit ROOM;
void create()
{
	set("short","����·");
	set("long",@LONG
�����Ǵ����ڣ�������һ��������·�ϣ����˶��Ǳ��صİ�
�����ˡ�Ҳ�����Щ��ԭ���������߶�����·����ͨ��ٵ�����
������·ͨ������ǵ����ţ����пɴ�㶫��ɽ��
LONG);
	set("objects", ([
	   __DIR__"npc/yetu": 2,
	]));
	set("outdoors", "dalis");
	set("exits",([ /* sizeof() == 1 */
	    "northwest"  : __DIR__"shuangheqiao",
	    "northeast"  : "/d/foshan/road1",
	]));
	set("coor/x", -38000);
	set("coor/y", -80000);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
// Room: /d/kunlun/jingshenfeng.c �����
// Last Modified by winder on Nov. 14 2000

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short","�����"NOR);
	set("long",@long
�۶��򱱣�����һ�룬ֻ���Ű����Ѱ����£���ֱͦ���㣬������
�����ԣ������ض���������ݱ���߳�ʮ���ɣ�ֻ��������֮����������
���ϸϸ�������������ƺ����ﻥ��Ӧ�𣬼��عأ���ת������ֻ
�������������һ���������ӱ��������ϥ�Ϸ���һ�Ž�β�٣����Ե�
�ࡣ��������ľ��ͣ������ȸ����ݺ���ž飬ϲȵ���˸磬������಻
֪�����ģ���������һ��һ�𣬻������ͳ���
long );
	set("objects",([
		CLASS_D("kunlun")+"/hezudao" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"sanshengao",
	]));
	set("outdoors", "kunlun");
	set("coor/x", -119980);
	set("coor/y", 40180);
	set("coor/z", 100);
	setup();
	replace_program(ROOM);
}
// Room: /d/suzhou/shuiwa.c
// Last Modified by winder on Mar. 8 2001

#include <ansi.h>;
inherit RIVER;

void create()
{
	::create();
	set("short", "������");
	set("long", @long
������Ϊ������¥�����׳ơ������롱���ഫ��ʩ�ڴ������ۡ���
����һ��ֱ̫ͨ�����˹������СϪ�����������ܹ������˺�֮�ϡ�
long);
	set("outdoors", "suzhou");
	set("exits",([
		"westup"    : __DIR__"shiyuan",
		"southwest" : __DIR__"caixiangjing",
	]));
	set("item_desc", ([
		"river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
	]));
	set("outdoors", "suzhou");
	set("coor/x", 930);
	set("coor/y", -1110);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һҶ���ۻ�����ʻ�˹���������Ů��һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("busy_msg",       "ֻ���ú�������������������������æ���š�����\n");
  set("wait_msg",       "����һֻ�ɴ��ϵĲ���Ů˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "����Ů��̤�Ű��������������һ�㣬���������ʻȥ��\n");
  set("leave_msg_in",   "����Ů��̤�Ű���������˵��һ��������ඡ������һ�㣬���������ʻȥ��\n");
  set("come_msg_in",    "����Ů˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("item_desc/river", HIC "\nֻ����������һҶС�ۣ�Ҳ�������("
                         HIY "yell" HIC ")һ������(" HIY "boat" HIC
                        ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤ˮ������\n" NOR);
  set("boat_short", "�ɴ�");    
  set("boat_desc",  @LONG
һҶС�ۣ����Ҳ�������ߡ��˸��ˡ�һ��ʮ����Ĳ���С������
�ֳ���ݣ����ڴ�β����ص��ۡ�
LONG );
  set("to",         __DIR__"szyunhe");  // �����յ� /*   ��ѡ   */
	setup();
}


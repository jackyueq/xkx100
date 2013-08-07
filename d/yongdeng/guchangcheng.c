// Room: /huanghe/guchangcheng.c
// Java Sep. 22 1998

#include <ansi.h>
inherit RIVER;

void create()
{
	::create();
	set("short", "�ų���");
	set("long", @LONG
������һ�ιų��ǡ��ഫ�ǵ�����ʼ���������ĸ�������������
ʮ�������ޡ����±�Ǩ���׺�ɣ������������һƬ���棬Ψһ
��ϡ�ɼ����Ǻ����Ƴɵķ��̨���С����һ������������ƺӴ�
������ȥ��������һҶС�۰ڶɳ˿ͣ�����Խ�(yell)һ�´��ҡ�
LONG );
	set("exits", ([
		"southwest" : __DIR__"yinpanshui",
		"southeast" : __DIR__"shimen",
	]));
	set("objects", ([
		__DIR__"npc/menmian" :1,
	]));
	set("outdoors", "yongdeng");
	set("coor/x", -19000);
	set("coor/y", 31000);
	set("coor/z", 0);
  set("yell_about", "����");             // yell ����
  set("river_type", "��");               // �����ϴ�������
  set("need_dodge",300);                 // ��Ҫ�����Ṧ
  set("come_msg_out",   "һҶ���ۻ�����ʻ�˹�����������һ��̤�Ű���ϵ̰����Ա�˿����¡�\n");
  set("busy_msg",       "ֻ���÷�������������������������æ���š�����\n");
  set("wait_msg",       "����һֻ�ɴ��ϵ�������˵�������������أ������ɡ�\n");
  set("leave_msg_out",  "������̤�Ű��������������һ�㣬��������г�ȥ��\n");
  set("leave_msg_in",   "������̤�Ű���������˵��һ��������ඡ������һ�㣬��������г�ȥ��\n");
  set("come_msg_in",    "����˵���������ϰ��ɡ����漴��һ��̤�Ű���ϵ̰���\n");
  set("item_desc/river", HIC "\nֻ����������һ���ɴ���Ҳ�������("
                         HIY "yell" HIC ")һ������(" HIY "boat" HIC
                        ")��\n���������������Ը��Ṧ����,Ҳ��ֱ��"
                        "��ˮ(" HIY "cross" HIC ")̤�Ӷ�����\n" NOR);
  set("boat_short", "�ɴ�");    
  set("boat_desc",  @LONG
�ƺ��ϵ�С�۶������ֺܼ�ª��С�ۡ�һλ����������վ�ڴ�β
�������ƶ棬һλ����׳˶��С����Ҳ�ڴ�ͷ�þ��ػ�ˮ�Ŵ����ƺ�
ˮ���ļ������»��ܿ죬���ȴ������
LONG );
  set("to",         "/d/lingzhou/xuanhebao");  // �����յ� /*   ��ѡ   */
	setup();
}

//Room: hcazhengdian.c ����������
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","����������");
      set("long",@LONG
�����Ƕ���ɽ�𶥻����ֵ���������ֹ�ģ��󣬵�����ש�̵أ��м�
�������������������������ǰ����һ��ľ���������������Թ�ߵ�ݡ�
�Դ����Ҹ���һ����ǽӴ���͵ĵط���������ͨ��һ����㳡��ֻ�ж�
�ҵ��Ӳ��ܹ�ȥ��
LONG);
      set("objects", ([
           CLASS_D("emei") + "/xin" : 1,
           __DIR__"npc/guest" : 1,
      ]));
      set("exits",([ /* sizeof() == 1 */
          "out"    : __DIR__"huacangan",
          "east"   : __DIR__"hcaeast", 
          "west"   : __DIR__"hcawest", 
          "south"  : __DIR__"hcaguangchang", 
      ]));
//      set("no_clean_up", 0);
	set("coor/x", -6200);
	set("coor/y", -1160);
	set("coor/z", 190);
	setup();
}
int valid_leave(object me, string dir)
{
	if (dir == "south" )
	{
		if(me->query("family/family_name") !="������")
		{
				if(present("jingxin shitai", environment(me)) && living(present("jingxin shitai", environment(me))))
				{
					return notify_fail(
"����ʦ̫�ȵ��������Ǳ����صأ���λ" + RANK_D->query_respect(me) + "��ֹ����\n");
				}
				else
					return ::valid_leave(me, dir);
		}
		else
			return ::valid_leave(me, dir);
	}
	else
		return ::valid_leave(me, dir);

}
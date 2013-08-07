// /d/xiakedao/shiroom.h
// Modified by Zeratul Jan 11 2001 һ����ֻ����һ�ֹ��򣬴�200����300��

int do_study(string arg)
{
	string *skill_name = ({
               "strike",          //�Կ��Ϻ�ӧ
               "sword",           //�⹳˪ѩ��
               "dodge",           //�����հ���
               "throwing",        //��������
               "hook",            //ʮ��ɱһ�� sword
               "leg",             //ǧ�ﲻ���� dodge
               "spear",           //���˷���ȥ dodge
               "stick",           //��������� dodge
               "unarmed",         //�й������� cuff or strike or unarmed
               "dagger",          //�ѽ�ϥǰ�� sword
               "parry",           //������캥
               "blade",           //����Ȱ����
               "axe",             //������Ȼŵ force ��ʱ��axe��
               "cuff",            //������Ϊ�� cuff or strike or unarmed
               "staff",           //�ۻ����Ⱥ�   ³������
               "claw",            //���������� cuff or strike or unarmed
               "hammer",          //���Իӽ� sword
               "hand",            //�������� force
               "array",           //ǧ���׳ʿ
               "force",           //ب�մ����� force
               "finger",          //����������   ָ��
               "club",            //��������Ӣ   ��ü��
               "whip",            //˭�������
               "taixuan-gong"     //����̫����
	});
	object me, where;
	int jing_cost, learn_pot, item, times, i, success=0;
	string skillname;
	string *old;

	me = this_player();
	if ( !me->query( "xkd/ling" ) )
		return notify_fail( "δ�����������������Թۿ�ʯ�ڡ�\n" );
	if( !arg ) return notify_fail("��Ҫ����ʲôѽ��\n");
	if( sscanf(arg, "%s %d", arg, times)!=2)
		return notify_fail("ָ���ʽ��think wall <����>\n");
	if( ( arg != "wall" ) )
		return notify_fail("ָ���ʽ��think wall <����>\n");
	if (times < 1 || times > 20)
		return notify_fail("�����������һ�Σ����Ҳ���ܳ�����ʮ�Ρ�\n");
	if ((int)me->query("combat_exp")<50000)
		return notify_fail("��ľ���̫��, û������ʯ�����ݡ�\n");
        if ((int)me->query("score")<1000)
		return notify_fail("�������̫��, û������ʯ�����ݡ�\n");
	if ((int)me->query_skill("literate",1)<1)
		return notify_fail("�����˰�! ������ȥѧ���Ļ��ɡ�\n");
	jing_cost = 30 + random(me->query_int());
	if( me->query("jing") < jing_cost * times)
		return notify_fail("������̫���ˣ���������ô��Σ���Ϣһ��������ɡ�\n");
	where = environment(me);
	switch (file_name(where))
	{
		case "/d/xiakedao/shiroom01": item = 0; break;
		case "/d/xiakedao/shiroom02": item = 1; break;
		case "/d/xiakedao/shiroom03": item = 2; break;
		case "/d/xiakedao/shiroom04": item = 3; break;
		case "/d/xiakedao/shiroom05": item = 4; break;
		case "/d/xiakedao/shiroom06": item = 5; break;
		case "/d/xiakedao/shiroom07": item = 6; break;
		case "/d/xiakedao/shiroom08": item = 7; break;
		case "/d/xiakedao/shiroom09": item = 8; break;
		case "/d/xiakedao/shiroom10": item = 9; break;
		case "/d/xiakedao/shiroom11": item = 10; break;
		case "/d/xiakedao/shiroom12": item = 11; break;
		case "/d/xiakedao/shiroom13": item = 12; break;
		case "/d/xiakedao/shiroom14": item = 13; break;
		case "/d/xiakedao/shiroom15": item = 14; break;
		case "/d/xiakedao/shiroom16": item = 15; break;
		case "/d/xiakedao/shiroom17": item = 16; break;
		case "/d/xiakedao/shiroom18": item = 17; break;
		case "/d/xiakedao/shiroom19": item = 18; break;
		case "/d/xiakedao/shiroom20": item = 19; break;
		case "/d/xiakedao/shiroom21": item = 20; break;
		case "/d/xiakedao/shiroom22": item = 21; break;
		case "/d/xiakedao/shiroom23": item = 22; break;
		case "/d/xiakedao/shiroom24": item = 23; break;
		default: break;
	}
	//����stringģʽ
	if (stringp(me->query("xkd/skill")))
	{
		old = me->query("xkd/skill");
		me->set("xkd/skill",({old}));
	}
	//�ĳ�string * ģʽ
	if (arrayp( me->query("xkd/skill")) && 
	sizeof(me->query("xkd/skill")) >= SCBORN_D->query_scborn_times(me)+1 &&
	member_array(skill_name[item],me->query( "xkd/skill" )) == -1	)
	{
		write( "ѧ��������Ķ��⣬�㻹��ר������" + to_chinese( me->query( "xkd/skill" )[0] ) + "ȥ�ɡ�\n" );
		return 1;
	}
	if ( !arrayp(me->query("xkd/skill")) ||	member_array(skill_name[item],me->query( "xkd/skill" )) == -1)
	{
		if (!arrayp(old = me->query("xkd/skill"))) old = ({});
		old += ({ skill_name[item] });
		me->set( "xkd/skill", old);
	}
	message_vision("$N��������ʯ���ϵ�ͼ����ע�͡�\n",me);
	for (i = 1; i<=times; i++)
	{
		me->receive_damage("jing",jing_cost);
		learn_pot = (int)(me->query("combat_exp")/10000) + random(me->query("int")) - (int)(me->query_skill("literate",1)/2);
		if (me->query_skill(skill_name[item],1)<200 && item != 23)
		{
			write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫����ˡ�\n");
			return 1;
		}
		if (me->query_skill(skill_name[item],1)>=300)
		{
			write("������ʯ��ڤ˼������һ�ᣬ��������Ķ���������˵̫ǳ���ˡ�\n");
			return 1;
		}
/*
		if (item == 4)
		{
			if ((string)me->query("gender") != "����" )
			{
				write("���Ǳ����Ǳ�а����ͼ�ף������񹦣������Թ���\n");
				return 1;
			}
		}
		else
*/
		{
			if (item == 23)
			{
				if (me->query("combat_exp")<10000)
				{
					write("�㾭�鲻�㣬�޷���ᵽʲô��\n");
					return 1;
				}
				if (random(me->query("kar")) < 25 ||
					(me->query_skill("taoism",1) < 100))
				{
					write("����ʯ���ϵ�����ģ����е��β��ˡ�\n");
					learn_pot = 0;
				}
			}
			else
			if( !SKILL_D(skill_name[item])->valid_learn(me) )
				return SKILL_D(skill_name[item])->valid_learn(me);
		}
		if((int)(me->query_skill(skill_name[item],1) * 
			me->query_skill(skill_name[item],1) * 
			me->query_skill(skill_name[item],1)) /10 >= me->query("combat_exp"))
		{
			write("�����ʯ��ڤ˼������һ�ᣬ�����ջ�\n");
			return 1;
		}
		if (learn_pot > 0)
		{
			me->improve_skill(skill_name[item], learn_pot);
			success=1;
		}
	}
	if (success == 1 && me->query("xkd/skill") != "taixuan-gong" )
		{write("�����ʯ��ڤ˼������"+chinese_number(times)+"�أ��ƺ���"+CHINESE_D->chinese(skill_name[item])+"��Щ�ĵá�\n");
	         me->add("score",-5*times);
	        }
	else
		write("�����ʯ��ڤ˼������"+chinese_number(times)+"�أ��ƺ���"+CHINESE_D->chinese(skill_name[item])+"ûɶ��ᡣ\n");
	success=0;
	return 1;
}

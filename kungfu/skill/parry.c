// parry.c �����м�
// Last Modified by winder on Mar. 10 2000

#include <ansi.h>;
inherit SKILL;
string type() { return "martial"; }
string martialtype() { return "skill"; }

int learn_bonus() { return 30; }
int practice_bonus() { return 30; }
int success() { return 30; }
int power_point(object me) { return 1; }
string *parry_msg = ({
	"ֻ�������ϡ�һ������$p���ˡ�\n",
	"�����������һ����$p�����ˡ�\n",
	"���Ǳ�$n�����б��мܿ���\n",
	"����$n����һ�࣬�����б��и񿪡�\n",
});
string *unarmed_parry_msg = ({
	"���Ǳ�$p���ˡ�\n",
	"�����$p�����ˡ�\n",
});

/* �м���Ϣ $n��$W: �м��˵ı��� $P��$l��$w: �����������岿λ�ͱ��� */
string *axe_msg = ({
	"ȴ��$n̤ǰһ��������$W����һ�ܣ��ܿ���$P��$w��\n",
	"$n���ͷ��б�����$W����$P��$l����һ�����ȵ�$P���Ʋ�������ͣ������\n",
	"ֻ�������ϡ�һ����$n����$W��$P��$w���ˡ�\n",
	"�����������һ����$n����һ�࣬������$W��$P��$w��\n",
});
string *blade_msg = ({
	"ȴ��$n̤ǰһ��������$W��������һ�ܣ��ܿ���$P��$w��\n",
	"$n���ͷ��б�����$W������$P�����о���һ�����ȵ�$P���ò�ͣ������\n",
	"ֻ�������ϡ�һ����$n����$W��$P��$w���ˡ�\n",
	"�����������һ����$n����һ�࣬������$W��$P��$w��\n",
	"$n�߾�����$W���������߶�ʮһ������$P��ͷ���£��Ƶ�$P��æ���ҡ�\n",
});
string *club_msg = ({
	"ȴ��$n��ǰ̤��һ����˫�ֺ��$W����һ�ܣ����üܿ���$P��$w��\n",
	"$n����һ��������$W����$P������һ����ȥ���ȵ�$P����Ծ����\n",
	"$n����$Wһ������$P��$w���������š�\n",
	"$n����$W��$P����һͱ���Ƶ�$P�ջ�$w�ԾȲ�Ͼ��\n",
});
string *dagger_msg = ({
	"ȴ��$n̤ǰһ��������$W����һ�񣬼ܿ���$P��$w��\n",
	"$næб��Ծǰ����ִ$W�ܲ�������$P��$l������$Pֻ�������������ܾ��ˡ�\n",
	"$n���ͷ��б�����$Wһ�ܣ�������$P��$w�ϣ�\n",
});
string *hammer_msg = ({
	"ȴ��$n̤ǰһ��������$W����һ�ң���ƫ��$P��$w��\n",
	"$n��������$W����ǰ��һ�����õ�ס��$P��$w��\n",
	"$n�������߶�ʮһ����������$W�����϶���һ����ȥ���ȵ�$P��$wһ���������˻�ȥ��\n",
});
string *hook_msg = ({
	"ȴ��$n̤ǰһ��������$W����һ�ܣ��ܿ���$P��$w��\n",
	"$n����$Wһ�������ù�����$P��$w��\n",
	"$n���ͷ��б�����$W����$P��$lһ����ȥ���ȵ�$P�����ԾȲ�����\n",
	"$n����$Wһ����������$P��$w�������⣡\n",
});
string *spear_msg = ({
	"ȴ��$n��ǰ̤��һ����˫�ֺ��$W����һ�ܣ����üܿ���$P��$w��\n",
	"$n����һ�������ǹβ����$P������ɨȥ���ȵ�$P�������ܣ�\n",
	"$n����$Wһ������$P��$w���������š�\n",
	"$n����$W��������$P���ľʹ̣��Ƶ�$P�ջ�$w�ԾȲ�Ͼ��\n",
});
string *staff_msg = ({
	"ȴ��$n��ǰ̤��һ����˫�ֺ��$W����һ�ܣ����üܿ���$P��$w��\n",
	"$n����һ���������β����$P������ɨȥ���ȵ�$P�������ܣ�\n",
	"$n����$Wһ������$P��$w���������š�\n",
	"$n�߾�$W��������$Pȫ�����£��Ƶ�$P��Ծ���ܲ�����\n",
});
string *stick_msg = ({
	"ȴ��$n��ǰ̤��һ����˫�ֺ��$W����һ�ܣ����üܿ���$P��$w��\n",
	"$n����һ���������β����$P������ɨȥ���ȵ�$P�������ܣ�\n",
	"$n����$Wһ������$P��$w���������š�\n",
	"$n����$W��$P����һͱ���Ƶ�$P�ջ�$w�ԾȲ�Ͼ��\n",
});
string *sword_msg = ({
	"ȴ��$n̤ǰһ����$Wбָ$P���ұۣ���Ҫʹ$P����$w������ˡ�\n",
	"$n����$W����$P���������ȵ�$P���г���$w��\n",
	"$n����$W��������⻮��$P�ұۣ��ȵ�$P�ջ�$w���С�\n",
	"$n����$Wб����ָ��$P��$w��·����������һ�����������˿�ȥ��\n",
	"$nһ��б������$Wббָ��$P��$l���ȵ�$P�����Ծȡ�\n",
	"$nͻȻһ������$P��$l����һ��ȴ�����������ţ�$P�����޴룬���Ʋ�������ͣ��������\n",
});
string *whip_msg = ({
	"ȴ��$n̤ǰһ����$W�ڰ���л�ΪһȦ��â������$P��$l����ʹ$P������ˡ�\n",
	"����$n������ϥ������$Wбָ������$P��$l��Ҫʹ$P������ˡ�\n"NOR,
	"ֻ��$n���������һš������$W���ֶ�������$P��$l��ȥ�������������ţ�$P�����޴룬���Ʋ�������ͣ��������\n",
	"��$n����$W�ڿ�һ��һ���������࣬�͵���$P��ͷ���£��ŵ�$P�����˼�����\n",
	"ȴ��$n������ң�����$W��������Ӱ����ɽ������ɨ��$P��ȫ��$Pһ�л��£�����ʯ���󺣣�������ס�ˡ�\n",
});

string query_parry_msg(object weapon)
{
	if( weapon )
	{
		switch (weapon->query("skill_type"))
		{
		case "axe"   :return axe_msg[random(sizeof(axe_msg))];break;
		case "blade" :return blade_msg[random(sizeof(blade_msg))];break;
		case "club"  :return club_msg[random(sizeof(club_msg))];break;
		case "dagger":return dagger_msg[random(sizeof(dagger_msg))];break;
		case "hammer":return hammer_msg[random(sizeof(hammer_msg))];break;
		case "hook"  :return hook_msg[random(sizeof(hook_msg))];break;
		case "spear" :return spear_msg[random(sizeof(spear_msg))];break;
		case "staff" :return staff_msg[random(sizeof(staff_msg))];break;
		case "stick" :return stick_msg[random(sizeof(stick_msg))];break;
		case "sword" :return sword_msg[random(sizeof(sword_msg))];break;
		case "whip"  :return whip_msg[random(sizeof(whip_msg))];break;
		default      :return parry_msg[random(sizeof(parry_msg))];break;
		}
	}
	else return unarmed_parry_msg[random(sizeof(unarmed_parry_msg))];
}
 
int help(object me)
{
	write(HIC"\n�����мܣ�"NOR"\n");
	write(@HELP

    �мܵĻ��������������м������ܾ��ܼ���Ϊ�мܡ�

	ѧϰҪ��
		��
HELP
	);
	return 1;
}

